using Connect4Game;
using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.ComponentModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Media;
using static Connect4_GUI.Board;


namespace Connect4_GUI
{
    internal class Board
    {
        public ObservableCollection<Cell> Cells { get; set; }

        private bool IsRed = true;

        public Board()
        {
            Cells = new ObservableCollection<Cell>();
            for (int row = 0; row < 6; row++)
            {
                for (int col = 0; col < 7; col++)
                {
                    Cells.Add(new Cell(col, row));
                }
            }
        }

        public void switchTurns()
        {
            IsRed = IsRed == true ? false : true; 
        }

        public void changeBox(Cell PickedCell)
        {
            foreach (Cell Cell in Cells)
            {
                if (Cell == PickedCell)
                {
                    if (IsRed)
                    {
                        Cell.Color = Colors.Red;
                        IsRed = false;
                        return;
                    }
                    Cell.Color = Colors.Yellow;
                    IsRed = true;
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
}
