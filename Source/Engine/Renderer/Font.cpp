#include "Font.h"

#include <iostream>

namespace viper {

    Font::~Font() {
        if (m_ttfFont != nullptr) {
            TTF_CloseFont(m_ttfFont);
        }
    }

    bool viper::Font::Load(const std::string& name, float fontSize) {
        m_ttfFont = TTF_OpenFont(name.c_str(), fontSize);
        if (m_ttfFont == nullptr) {
            std::cerr << "Could not load font: " << name << std::endl;
            return false;
        }

        return true;
}

}
