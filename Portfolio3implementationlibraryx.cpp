#include "Portfolio3.h"
#include <iostream>

Port3::Port3(int a, int b, int e, int smin, int smax)
    : rowval(a), colval(b),
    birthnm(e), survivalminimum(smin), survivalmaximum(smax),
    gridlayout(rowval, vector<bool>(colval, false)),
    buffermode(rowval, vector<bool>(colval, false))
{
}

Port3::~Port3() = default;

bool Port3::withinrange(int a, int b) const {
    return a >= 0 && a < rowval && b >= 0 && b < colval;
}

int Port3::neighboringcellstracker(int a, int b) const {
    int tracker = 0;
    for (int fx = -1; fx <= 1; ++fx) {
        for (int fg = -1; fg <= 1; ++fg) {
            if ((fx || fg) && withinrange(a + fx, b + fg) && gridlayout[a + fx][b + fg])
                ++tracker;
        }
    }
    return tracker;
}

void Port3::makefirstcells() {
    int livetracker;
    cout << "Live cells: ";
    while (!(cin >> livetracker) || livetracker < 0) {
        cin.clear(); cin.ignore(1000, '\n');
        cout << "Enter non-negative number: ";
    }
    for (int i = 0; i < livetracker; ++i) {
        int a, b;
        cout << "Cell " << i + 1 << " row col: ";
        while (!(cin >> a >> b) || !withinrange(a, b)) {
            cin.clear(); cin.ignore(1000, '\n');
            cout << "Invalid, try again: ";
        }
        gridlayout[a][b] = true;
    }
}

void Port3::movetogeneration() {
    for (int r = 0; r < rowval; ++r) {
        for (int c = 0; c < colval; ++c) {
            int n = neighboringcellstracker(r, c);
            if (!gridlayout[r][c] && n == birthnm)
                buffermode[r][c] = true;
            else if (gridlayout[r][c] && n >= survivalminimum && n <= survivalmaximum)
                buffermode[r][c] = true;
            else
                buffermode[r][c] = false;
        }
    }
    gridlayout.swap(buffermode);
}

void Port3::displaygridlayout() const {
    for (int r = 0; r < rowval; ++r) {
        for (int c = 0; c < colval; ++c)
            cout << (gridlayout[r][c] ? 'O' : '.') << ' ';
        cout << "\n";
    }
}
