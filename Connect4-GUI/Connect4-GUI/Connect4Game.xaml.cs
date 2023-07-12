using Connect4_GUI;
using System;
using System.Collections.ObjectModel;
using System.ComponentModel;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Media;
using System.Windows.Media.Animation;

namespace Connect4Game
{
    public partial class MainWindow : Window
    {
        public ObservableCollection<Cell> Cells { get; set; }
        public string message;

        Connector connector;
        public MainWindow()
        {
            InitializeComponent();
            connector = new Connector();
            connector.initPipe();
            DataContext = this;
            Cells = new ObservableCollection<Cell>();

            // Generate the cells
            for (int row = 0; row < 6; row++)
            {
                for (int col = 0; col < 7; col++)
                {
                    var cell = new Cell();
                    cell.col = col;
                    Cells.Add(cell);
                }
            }
        }

        private void Cell_Click(object sender, RoutedEventArgs e)
        {
            var clickedCell = (Button)sender;
            var cell = (Cell)clickedCell.DataContext;
            setBoard(connector.sendData(cell.col.ToString()));

        }

        private void Reset(object sender, RoutedEventArgs e)
        {
            foreach (Cell cell in Cells)
            {
                cell.Color = Colors.White;
            }
        }

        private void setBoard(string board)
        {
            if (board[0] == '2')
            {
                MessageText.Visibility = Visibility.Visible;

                // Start the fade-out animation
                DoubleAnimation fadeOutAnimation = new DoubleAnimation();
                fadeOutAnimation.From = 1.0;
                fadeOutAnimation.To = 0.0;
                fadeOutAnimation.Duration = TimeSpan.FromSeconds(1);
                fadeOutAnimation.Completed += (s, _) =>
                {
                    // Animation completed, hide the message
                    //MessageText.Visibility = Visibility.Collapsed;
                };

                MessageText.BeginAnimation(OpacityProperty, fadeOutAnimation);
                return;
            }
            for (int i = 1; i < board.Length; i++)
            {
                Cells[i - 1].Color = board[i] == '-' ? Colors.White : (board[i] == 'R' ? Colors.Red : Colors.Yellow);
            }
        }
    }

    public class Cell : INotifyPropertyChanged
    {
        private Color _color;
        public int col;

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
