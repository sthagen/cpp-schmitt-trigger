#include <iostream>
#include "../schmitt/trigger.hpp"

int main() {
    std::string const tt_ni_disp{"Not Inverting"};
    std::string const tt__i_disp{"Inverting"};
    
    auto const low = -1.f, high = 2.f;
    bool const default_out = false;
    
    auto st__i = schmitt::trigger_inverting<float>(low, high, default_out);
    auto st_ni = schmitt::trigger<float>(low, high, default_out);
   
    std::cout << "st.context(" << tt__i_disp << ", "
              << low << ", " << high << ", " << default_out << ") ... and " << tt_ni_disp << ":\n";
    float m = 2., step = 1.f;
    auto cycles = 2;
    do {
        std::cout << "Rising ...\n";
        for (; m < high + step ; m += step) {
            std::cout << "  st(" << m << ") --> \t" << st__i(m) << "\t" << st_ni(m) << "\n";
        }
        std::cout << "  st(" << m << ") --> \t" << st__i(m) << "\t" << st_ni(m) << "\n";
        std::cout << "Sinking ...\n";
        for (; m > low - step; m -= step) {
            std::cout << "  st(" << m << ") --> \t" << st__i(m) << "\t" << st_ni(m) << "\n";
        }
        std::cout << "  st(" << m << ") --> \t" << st__i(m) << "\t" << st_ni(m) << "\n";
    } while (--cycles);
    return 0;
}
