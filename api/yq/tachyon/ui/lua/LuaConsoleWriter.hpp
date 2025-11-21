////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/ui/UIConsoleWriter.hpp>
#include <yq/typedef/color.hpp>

namespace yq::tachyon {
    class LuaConsole;

    class LuaConsoleWriter : public UIConsoleWriter {
    public:
    public:
        LuaConsoleWriter();
        LuaConsoleWriter(LuaConsole*);
        LuaConsoleWriter(const LuaConsoleWriter&);
        ~LuaConsoleWriter();
        
        LuaConsole*  element();

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
