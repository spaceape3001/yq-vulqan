////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/core/Stream.hpp>
#include <yq/color/RGB.hpp>
#include <yq/color/RGBA.hpp>
#include <yq/tachyon/ui/UIConsole.hpp>
#include <yq/typedef/color.hpp>
#include <filesystem>

namespace yq::lua {
    class LuaExecuteReply;
    
    class LuaConsoleWriter;

    class LuaConsole : public tachyon::UIConsole {
        YQ_OBJECT_DECLARE(LuaConsole, tachyon::UIConsole)
    public:
    
        using Writer = LuaConsoleWriter;
    
        struct Streamer;
        
        LuaConsole(tachyon::UIFlags flags={});
        LuaConsole(const LuaConsole&);
        ~LuaConsole();

        Streamer    command();
        void        command(std::string_view);
        void        command(set_k, const color_t&);
    
        Streamer    debug();
        void        debug(std::string_view);
        void        debug(set_k, const color_t&);

        Streamer    error();
        void        error(std::string_view);
        void        error(set_k, const color_t&);
        void        error_code(set_k, const color_t&);

        Streamer    file();
        void        file(const std::filesystem::path&);
        void        file(std::string_view);
        void        file(set_k, const color_t&);

        Streamer    info();
        void        info(std::string_view);
        void        info(set_k, const color_t&);

        Streamer    output();
        void        output(std::string_view);
        void        output(set_k, const color_t&);

        using tachyon::UIConsole::submit;
        void        submit(const LuaExecuteReply&);
        
        Streamer    warning();
        void        warning(std::string_view);
        void        warning(set_k, const color_t&);

        static void init_meta();

    protected:
        LuaConsole*      clone() const override;

    private:
        struct Channel {
            RGBA4F      color;
        };
        
        struct {
            Channel     command;
            Channel     debug;
            Channel     error;
            Channel     errorCode;
            Channel     file;
            Channel     info;
            Channel     output;
            Channel     warning;
        } m_channel;
        
        void    _submit(const Channel&, std::string_view);
    };
    
    class LuaConsole::Streamer : public Stream {
    public:
        ~Streamer();

    protected:
        bool    write(const char*, size_t) override;
        
    private:
        friend class LuaConsole;
        Streamer(LuaConsole&, const Channel&);
    
        void _post();
    
        LuaConsole&   m_ui;
        const Channel&  m_channel;
        std::string     m_buffer;
    };
    
}
