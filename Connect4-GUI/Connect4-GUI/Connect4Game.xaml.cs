using Connect4_GUI;
using System.Collections.ObjectModel;
using System.ComponentModel;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Media;

namespace Connect4Game
{
    public partial class MainWindow : Window
    {
        private Board _Board { get; set; }

        


        public MainWindow()
        {
            InitializeComponent();
            DataContext = this;
            _Board = new Board();

            // Generate the cells
            
        }

        private void Cell_Click(object sender, RoutedEventArgs e)
        {
            var clickedCell = (Button)sender;
            var cell = (Cell)clickedCell.DataContext;

            // TODO: Handle the logic for the clicked cell
            // You can communicate with the other program here to get the board state

            // Example: Change the color of the clicked cell to indicate selection
            

            if (cell.Color == Colors.Red || cell.Color == Colors.Yellow)
            {
                return;
            }

            
        }
    }

    public class Cell : INotifyPropertyChanged
    {
        private Color _color;
        public int x;
        public int y;

        public Cell(int x, int y)
        {
            this.x = x;
            this.y = y;
        }

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
