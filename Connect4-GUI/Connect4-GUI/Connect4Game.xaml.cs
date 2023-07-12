using System.Collections.ObjectModel;
using System.ComponentModel;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Media;

namespace Connect4Game
{
    public partial class MainWindow : Window
    {
        public ObservableCollection<Cell> Cells { get; set; }

        public MainWindow()
        {
            InitializeComponent();
            DataContext = this;
            Cells = new ObservableCollection<Cell>();

            // Generate the cells
            for (int row = 0; row < 6; row++)
            {
                for (int col = 0; col < 7; col++)
                {
                    Cells.Add(new Cell());
                }
            }
        }

        private void Cell_Click(object sender, RoutedEventArgs e)
        {
            var clickedCell = (Button)sender;
            var cell = (Cell)clickedCell.DataContext;

            // TODO: Handle the logic for the clicked cell
            // You can communicate with the other program here to get the board state

            // Example: Change the color of the clicked cell to indicate selection
            cell.Color = Colors.Yellow;
        }

        private void Reset(object sender, RoutedEventArgs e)
        {
            foreach (Cell cell in Cells)
            {
                cell.Color = Colors.White;
            }
        }
    }

    public class Cell : INotifyPropertyChanged
    {
        private Color _color;

        public Color Color
        {
            get { return _color; }
            set
            {
                _color = value;
                OnPropertyChanged("Color");
            }
        }

        public event PropertyChangedEventHandler PropertyChanged;

        protected virtual void OnPropertyChanged(string propertyName)
        {
            PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(propertyName));
        }
    }
}
