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
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
            resultLabel.Content = "1";

            //Event handler initialization for buttons
            acButton.Click += AcButton_Click;

        }

        private void AcButton_Click(object sender, RoutedEventArgs e)
        {
            resultLabel.Content = "0";
        }

        private void zeroButton_Click(object sender, EventArgs e)
        { 
            if(resultLabel.Content.ToString()=="0")
            {
                Console.WriteLine("The Value is already Zero");
            }
            else
            {
                resultLabel.Content = $"{resultLabel.Content}0";
            }
        }
    }
}
