#include <ftxui/screen/screen.hpp>
#include <ftxui/screen/color.hpp>
#include <thread>
#include <chrono>
#include <iostream>
#include <vector>
#include <string>
#include <ftxui/component/component.hpp>
#include <ftxui/component/screen_interactive.hpp>

using namespace std;
using namespace ftxui;

int main()
{
    auto screen = Screen::Create(Dimension::Fixed(100), Dimension::Fixed(30));

    // === Frame 1: Preparado ===
    const vector<string> frame1 = {
        "                                            _--_     dMb ",
        "                                         __(._  )   d0P",
        "                                           <  (D)  .MP",
        "                                         .~ \\ /~```M-. ",
        "                                       .~    V    Mo_ \\             ",
        "-------============((((}{)             (   (___. {:)-./ ",
        "                                        ~._____.(:}       ",
        "                        '94 the wolfe    /     .M\\   ",
        "                                        /      \"\" \\",
        "                                        |    /\\   |",
        "                                        /   /  \\   \\",
        "                                       /   /    \\   \\",
        "                                       \\__/      \\__/",
        "                                       / /        | |",
        "                                      .^V^.      .^V^.",
        "                                       +-+        +-+"};

    // === Frame 2: Swing ===
    const vector<string> frame2 = {
        "                             _--_     ",
        "                            ( A's)   ",
        "                            /___7",
        "                          .~~\\ /~~.",
        "                        /\"\"_  V    \\             ",
        "                       om /____/   / ",
        "                    .mmmC=\"_      _/",
        "-----===(((((}{).MMM \"\"  |  `\"---\"           ",
        "           ..mMMM\"\"       |        \\",
        "           (  )\"          \\    /\\   |",
        "                          /   /  \\   \\  '94 the wolfe",
        "                        /\"   /    \\   \\",
        "                        \\__/\"      \\__/",
        "                        / /        | |",
        "                       .^V^.      .^V^.",
        "                        +-+        +-+"};

    // === Frame 3: Bola volando ===
    const vector<string> frame3 = {
        "                                  dMb",
        " +  +    +                         MMM         _--_     ",
        "                +                   MMM       ( A's)   ",
        "+  (}{)                              MMM      /___7",
        "     \\\\\\   +                          \"MM   .~~\\ /~~.",
        "  +    \\\\                               MM/\"\"_  V    \\             ",
        "        \"\\                               om /____/   / ",
        "                                         '{:)      _/",
        "                                            `\"---\" |          ",
        "                                           |        \\",
        "                                           \\    /\\   |",
        "                                           /   /  \\   \\",
        "                                         /\"   /    \\   \\",
        "                                         \\__/\"      \\__/",
        "                                         / /        | |",
        "                                        .^V^.      .^V^.",
        "                                         +-+        +-+",
        "                                              ",
        "                                           '94 the wolfe"};

    // === Frame 4: Imagen ASCII grande (redonda) ===
    const vector<string> frame4 = {
        "\"      .-::\":-.\"",
        "\"    .'''..''..'.\"",
        "\"   /..''..''..''\\\"",
        "\"  ;'..''..''..''.;\"",
        "\"  ;'..''..''..'..;\"",
        "\"   \\..''..''..''/\"",
        "\"    '.''..''...'\"",
        "\"jgs   '-..::-'\""};

    // === Frame 5: Imagen ASCII pequeña redonda ===
    const vector<string> frame5 = {
        "\"   .--.   \"",
        "\"  /    \\  \"",
        "\" |      | \"",
        "\"  \\    /  \"",
        "\"   '--'   \""};
    const vector<string> frame6 = {
        "."};

    // Guardar los frames en un vector
    vector<vector<string>> frames = {frame1, frame2, frame3, frame4, frame5,frame6};

    // === Animación principal ===
    for (int ciclo = 0; ciclo < 6; ++ciclo)
    {
        for (size_t i = 0; i < frames.size(); ++i)
        {
            auto &frame = frames[i];
            screen.Clear();

            int y = 2;
            for (auto &linea : frame)
            {
                int x = 5;
                for (char c : linea)
                {
                    if (x < screen.dimx() && y < screen.dimy())
                    {
                        auto &px = screen.PixelAt(x, y);
                        px.character = c;

                        // Colorear solo los frames del beisbolista (1 a 3)
                        if (i < 3)
                        {
                            if (c == 'M' || c == 'm')
                                px.foreground_color = Color::Yellow; // cuerpo
                            else if (c == '(' || c == ')' || c == '{' || c == '}')
                                px.foreground_color = Color::Red; // bate y movimiento
                            else if (c == '/' || c == '\\')
                                px.foreground_color = Color::GrayLight; // brazos
                            else
                                px.foreground_color = Color::White;
                        }
                        else
                        {
                            px.foreground_color = Color::White; // las pelotas en blanco
                        }
                    }
                    x++;
                }
                y++;
            }

            screen.Print();
            cout << screen.ResetPosition();
            this_thread::sleep_for(chrono::milliseconds(700));
        }
    }

    return 0;
}
