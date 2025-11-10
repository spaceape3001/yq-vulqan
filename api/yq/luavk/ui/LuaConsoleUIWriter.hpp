////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/ui/UIConsoleWriter.hpp>
#include <yq/typedef/color.hpp>

namespace yq::lua {
    class LuaConsoleUI;

    class LuaConsoleUIWriter : public tachyon::UIConsoleWriter {
    public:
    public:
        LuaConsoleUIWriter();
        LuaConsoleUIWriter(LuaConsoleUI*);
        LuaConsoleUIWriter(const LuaConsoleUIWriter&);
        ~LuaConsoleUIWriter();
        
        LuaConsoleUI*  element();

        void        command(const color_t&);
        void        debug(const color_t&);
        void        error(const color_t&);
        void        error_code(const color_t&);
        void        file(const color_t&);
        void        info(const color_t&);
        void        output(const color_t&);
        void        warning(const color_t&);
    };
}
