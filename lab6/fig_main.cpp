//
// Created by Daniil Borovoy <daniilborovoy42@gmail.com> on 13.12.2022.
//

#include "fig_main.h"
#include "new_fig.h"

void fig_main::run_fig_main() {
    Rectangle test(4);
    Circle test1(2);
    Rectangle test2(1, 2);
    Triangle test3(3, 4, 5);
    Figure *mas[4]{&test, &test1, &test2, &test3};
    for (auto i: mas) {
        i->show();
    }
}
