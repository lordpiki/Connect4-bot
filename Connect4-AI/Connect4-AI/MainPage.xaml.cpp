#include "pch.h"
#include "MainPage.xaml.h"

using namespace Connect4_AI;

MainPage::MainPage()
{
    InitializeComponent();
    Loaded += ref new Windows::UI::Xaml::RoutedEventHandler(this, &MainPage::OnLoaded);
}

void MainPage::OnLoaded(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
    // Your code for Connect4-AI logic here
    StatusTextBlock->Text = "Connect4-AI app is working!";
}
