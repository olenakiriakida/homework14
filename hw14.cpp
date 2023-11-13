
#include <iostream>
#include <windows.h>
using namespace std;

class Application
{
    static Application* instance;
    static string title;

    Application()
    {
        title = "Default Title";
    }

public:
    static Application* GetInstance()
    {
        return instance == nullptr ? instance = new Application() : instance;
    }

    static void StartRandomize()
    {
        srand(time(NULL));
        cout << "Cin count of random number: ";
        int count = 0;
        cin >> count;
        for (int i = 0; i < count; i++)
        {
            int random_number = rand();
            cout << "Random number: " << random_number << "\n";
        }
    }

    static void SetTitle(const string& new_title)
    {
        title = new_title;
        SetConsoleTitleA(title.c_str());
    }

    static string GetTitle()
    {
        return title;
    }

    static void ClearScreen()
    {
        cout << "Press 1 for cleaning window: ";
        int press_key;
        cin >> press_key;
        if (press_key == 1)
        {
            system("cls");
        }
        else
        {
            throw "Error! You need press 1 for cleaning window...\n";
        }
    }

    static void SetTextColor(int color)
    {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, color);
    }

    static void Exit()
    {
        exit(0);
    }
};

Application* Application::instance = nullptr;
string Application::title = "";

int main()
{
    Application::GetInstance();
    Application::SetTextColor(4);
    Application::SetTitle("Title");
    Application::StartRandomize();
    Application::ClearScreen();
    Application::Exit();

}