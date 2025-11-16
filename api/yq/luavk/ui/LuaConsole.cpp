////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "LuaConsole.hpp"
#include "LuaConsoleWriter.hpp"

#include <yq/color/colors.hpp>
#include <yq/luavk/reply/LuaExecuteReply.hpp>
#include <yq/luavk/request/LuaExecuteFileRequest.hpp>
#include <yq/luavk/request/LuaExecuteStringRequest.hpp>
#include <yq/tachyon/ui/UIElementMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::lua::LuaConsole)

namespace yq::lua {
    void LuaConsole::init_meta()
    {
        auto w = writer<LuaConsole>();
        w.description("Console for Lua");
    }

    LuaConsole::LuaConsole(tachyon::UIFlags flags) : tachyon::UIConsole(flags), 
        m_channel{
            .command={
                .color  = rgba4f(yq::color::LimeGreen)
            },
            .debug={
                .color  = rgba4f(yq::color::Orange)
            },
            .error={
                .color  = rgba4f(yq::color::Red)
            },
            .errorCode={
                .color  = rgba4f(yq::color::Magenta)
            },
            .file={
                .color  = rgba4f(yq::color::Cyan)
            },
            .info={
                .color  = rgba4f(yq::color::Bone)
            },
            //static constexpr auto kClrInput         = (RGBA4F) rgba(yq::color::Green, 255);
            .output={
                .color  = rgba4f(yq::color::White)
            },
            .warning={
                .color  = rgba4f(yq::color::Yellow)
            }
        }
    {
    }
    
    LuaConsole::LuaConsole(const LuaConsole& cp) : tachyon::UIConsole(cp), m_channel(cp.m_channel)
    {
    }
    
    LuaConsole::~LuaConsole()
    {
    }

    void    LuaConsole::_submit(const Channel&ch, std::string_view txt)
    {
        submit({.color=ch.color}, txt);
    }

    LuaConsole* LuaConsole::clone() const 
    {
        return new LuaConsole(*this);
    }

    LuaConsole::Streamer    LuaConsole::command()
    {
        return Streamer(*this, m_channel.command);
    }
    
    void        LuaConsole::command(std::string_view txt)
    {
        _submit(m_channel.command, txt);
    }
    
    void        LuaConsole::command(set_k, const color_t& v)
    {
        m_channel.command.color   = rgba4f(v);
    }

    LuaConsole::Streamer    LuaConsole::debug()
    {
        return Streamer(*this, m_channel.debug);
    }
    
    void        LuaConsole::debug(std::string_view txt)
    {
        _submit(m_channel.debug, txt);
    }
    
    void        LuaConsole::debug(set_k, const color_t& v)
    {
        m_channel.debug.color   = rgba4f(v);
    }

    LuaConsole::Streamer    LuaConsole::error()
    {
        return Streamer(*this, m_channel.error);
    }
    
    void        LuaConsole::error(std::string_view txt)
    {
        _submit(m_channel.error, txt);
    }
    
    void        LuaConsole::error(set_k, const color_t& v)
    {
        m_channel.error.color   = rgba4f(v);
    }

    void        LuaConsole::error_code(set_k, const color_t& v)
    {
        m_channel.errorCode.color   = rgba4f(v);
    }

    LuaConsole::Streamer    LuaConsole::file()
    {
        return Streamer(*this, m_channel.file);
    }
    
    void        LuaConsole::file(const std::filesystem::path&v)
    {
        _submit(m_channel.file, v.string());
    }
    
    void        LuaConsole::file(std::string_view txt)
    {
        _submit(m_channel.file, txt);
    }
    
    void        LuaConsole::file(set_k, const color_t& v)
    {
        m_channel.file.color    = rgba4f(v);
    }

    LuaConsole::Streamer    LuaConsole::info()
    {
        return Streamer(*this, m_channel.info);
    }
    
    void        LuaConsole::info(std::string_view txt)
    {
        _submit(m_channel.info, txt);
    }
    
    void        LuaConsole::info(set_k, const color_t& v)
    {
        m_channel.info.color = rgba4f(v);
    }

    LuaConsole::Streamer    LuaConsole::output()
    {
        return Streamer(*this, m_channel.output);
    }
    
    void        LuaConsole::output(std::string_view txt)
    {
        _submit(m_channel.output, txt);
    }
    
    void        LuaConsole::output(set_k, const color_t& v)
    {
        m_channel.output.color = rgba4f(v);
    }

    void        LuaConsole::submit(const LuaExecuteReply& rep)
    {
        if(const LuaExecuteStringRequest* cmd = dynamic_cast<const LuaExecuteStringRequest*>(rep.request())){
            command(cmd->text());
        }
        if(const LuaExecuteFileRequest* cmd = dynamic_cast<const LuaExecuteFileRequest*>(rep.request())){
            file(cmd->file());
        }

        if(!rep.output().empty())
            output(rep.output());
        if(!rep.warning().empty())
            warning(rep.warning());
        if(!rep.error().empty())
            error(rep.error());
        if(rep.error_code() != std::error_code())
            _submit(m_channel.errorCode, rep.error_code().message());
    }
    
    LuaConsole::Streamer    LuaConsole::warning()
    {
        return Streamer(*this, m_channel.warning);
    }
    
    void        LuaConsole::warning(std::string_view txt)
    {
        _submit(m_channel.warning, txt);
    }
    
    void        LuaConsole::warning(set_k, const color_t& v)
    {
        m_channel.warning.color = rgba4f(v);
    }


////////////////////////////////////////////////////////////////////////////////

    LuaConsole::Streamer::Streamer(LuaConsole& ui, const Channel& ch) : m_ui(ui), m_channel(ch)
    {
    }

    LuaConsole::Streamer::~Streamer()
    {
        _post();
    }

    void LuaConsole::Streamer::_post()
    {
        if(m_buffer.empty())
            return;
        m_ui._submit(m_channel, m_buffer);
        m_buffer.clear();
    }

    bool    LuaConsole::Streamer::write(const char*buf, size_t cb) 
    {
        if(buf && cb){
            m_buffer += std::string_view(buf, cb);
        }
        return true;
    }

////////////////////////////////////////////////////////////////////////////////

    LuaConsoleWriter::LuaConsoleWriter() = default;
    LuaConsoleWriter::LuaConsoleWriter(const LuaConsoleWriter&) = default;
    LuaConsoleWriter::~LuaConsoleWriter() = default;

    LuaConsole* LuaConsoleWriter::element()
    {
        return static_cast<LuaConsole*>(m_ui);
    }
    
    LuaConsoleWriter::LuaConsoleWriter(LuaConsole* ui) : tachyon::UIConsoleWriter(ui)
    {
    }

    void    LuaConsoleWriter::command(const color_t& v)
    {
        if(LuaConsole*p  = element())
            p->command(SET, v);
    }
    
    void    LuaConsoleWriter::debug(const color_t& v)
    {
        if(LuaConsole*p  = element())
            p->debug(SET, v);
    }
    
    void    LuaConsoleWriter::error(const color_t& v)
    {
        if(LuaConsole*p  = element())
            p->error(SET, v);
    }
    
    void    LuaConsoleWriter::error_code(const color_t& v)
    {
        if(LuaConsole*p  = element())
            p->error_code(SET, v);
    }
    
    void    LuaConsoleWriter::file(const color_t& v)
    {
        if(LuaConsole*p  = element())
            p->file(SET, v);
    }
    
    void    LuaConsoleWriter::info(const color_t& v)
    {
        if(LuaConsole*p  = element())
            p->info(SET, v);
    }
    
    void    LuaConsoleWriter::output(const color_t& v)
    {
        if(LuaConsole*p  = element())
            p->output(SET, v);
    }
    
    void    LuaConsoleWriter::warning(const color_t& v)
    {
        if(LuaConsole*p  = element())
            p->warning(SET, v);
    }

}

