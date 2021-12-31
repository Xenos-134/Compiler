using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace HelloWorldWPF
{
    public partial class MainWindow : Window
    {
        double lastNumber, result;
        SelectedOperator selectedOperator;
        public MainWindow()
        {
            InitializeComponent();
            //resultLabel.Content = "1";

            //Event handler initialization for buttons
            acButton.Click += AcButton_Click;
            negativeButton.Click += NegativeButton_Click;
            percentageButton.Click += PercentageButton_Click;
            

        }

        public void EqualButton_Click(object sender, EventArgs e)
        {
            double newNumber;
            if(double.TryParse(resultLabel.Content.ToString(), out newNumber))
            {
                switch(selectedOperator)
                {
                    case SelectedOperator.Addition:
                        result = Operations.Add(lastNumber, newNumber);
                        break;
                    case SelectedOperator.Multiplication:
                        result = Operations.Multiplicate(lastNumber, newNumber);
                        break;
                    case SelectedOperator.Division:
                        result = Operations.Divide(lastNumber, newNumber); 
                        break;
                    case SelectedOperator.Subtraction:
                        result = Operations.Subtract(lastNumber, newNumber);
                        break;
                }

                resultLabel.Content = result.ToString();
            }
        }

        private void OperatorButton_Click(object sender, EventArgs e)
        {
            //saves current number
            double.TryParse(resultLabel.Content.ToString(), out lastNumber);
            resultLabel.Content = "0";
            if (sender == multiplicationButton)
            {
                selectedOperator = SelectedOperator.Multiplication;
                
            }
            if(sender == plusButton)
            {
                selectedOperator = SelectedOperator.Addition;
            }
            if (sender == minusButton)
            {
                selectedOperator = SelectedOperator.Subtraction;
            }
            if (sender == divisionButton)
            {
                selectedOperator = SelectedOperator.Division;
            }
        }
        

        public void NumberButton_Click(object sender, EventArgs e)
        {
            double selectedNumber;
            if(double.TryParse((sender as Button).Content.ToString(), out selectedNumber))
            {
                if (resultLabel.Content.ToString() == "0") resultLabel.Content = "";
                resultLabel.Content = $"{resultLabel.Content}{selectedNumber.ToString()}";
            }
        }

        private void PercentageButton_Click(object sender, RoutedEventArgs e)
        {
            if(double.TryParse(resultLabel.Content.ToString(), out lastNumber))
            {
                lastNumber = lastNumber / 100;
                resultLabel.Content = lastNumber.ToString();
            }
        }

        private void NegativeButton_Click(object sender, RoutedEventArgs e)
        {
            if (double.TryParse(resultLabel.Content.ToString(), out lastNumber))
            {
                lastNumber = -1 * lastNumber;
                resultLabel.Content = lastNumber.ToString();
            }
        }

        //Erases all items from result row
        private void AcButton_Click(object sender, RoutedEventArgs e)
        {
            resultLabel.Content = "0";
        }

        private void zeroButton_Click(object sender, EventArgs e)
        { 
            if(resultLabel.Content.ToString()!="0")
            {
                resultLabel.Content = $"{resultLabel.Content}0";
            }

        }

        public enum SelectedOperator
        {
            Addition,
            Subtraction,
            Multiplication,
            Division,
        }
    }

    public class Operations
    {
        public static double Add(double a, double b)
        { return a + b; }
        
        public static double Subtract(double a, double b)
        { return a - b; }

        public static double Multiplicate(double a, double b)
        { return a*b; }

        public static double Divide(double a, double b)
        { return a/b; }
    }
}
