////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "LuaConsoleUI.hpp"
#include "LuaConsoleUIWriter.hpp"

#include <yq/color/colors.hpp>
#include <yq/luavk/event/ExecuteFileEvent.hpp>
#include <yq/luavk/event/ExecuteStringEvent.hpp>
#include <yq/tachyon/ui/UIElementMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::lua::LuaConsoleUI)

namespace yq::lua {
    void LuaConsoleUI::init_meta()
    {
        auto w = writer<LuaConsoleUI>();
        w.description("Console for Lua");
    }

    LuaConsoleUI::LuaConsoleUI(std::string_view k, tachyon::UIFlags flags) : tachyon::UIConsole(k, flags), 
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
    
    LuaConsoleUI::LuaConsoleUI(const LuaConsoleUI& cp) : tachyon::UIConsole(cp), m_channel(cp.m_channel)
    {
    }
    
    LuaConsoleUI::~LuaConsoleUI()
    {
    }

    void    LuaConsoleUI::_submit(const Channel&ch, std::string_view txt)
    {
        submit({.color=ch.color}, txt);
    }

    LuaConsoleUI* LuaConsoleUI::clone() const 
    {
        return new LuaConsoleUI(*this);
    }

    LuaConsoleUI::Streamer    LuaConsoleUI::command()
    {
        return Streamer(*this, m_channel.command);
    }
    
    void        LuaConsoleUI::command(std::string_view txt)
    {
        _submit(m_channel.command, txt);
    }
    
    void        LuaConsoleUI::command(set_k, const color_t& v)
    {
        m_channel.command.color   = rgba4f(v);
    }

    LuaConsoleUI::Streamer    LuaConsoleUI::debug()
    {
        return Streamer(*this, m_channel.debug);
    }
    
    void        LuaConsoleUI::debug(std::string_view txt)
    {
        _submit(m_channel.debug, txt);
    }
    
    void        LuaConsoleUI::debug(set_k, const color_t& v)
    {
        m_channel.debug.color   = rgba4f(v);
    }

    LuaConsoleUI::Streamer    LuaConsoleUI::error()
    {
        return Streamer(*this, m_channel.error);
    }
    
    void        LuaConsoleUI::error(std::string_view txt)
    {
        _submit(m_channel.error, txt);
    }
    
    void        LuaConsoleUI::error(set_k, const color_t& v)
    {
        m_channel.error.color   = rgba4f(v);
    }

    void        LuaConsoleUI::error_code(set_k, const color_t& v)
    {
        m_channel.errorCode.color   = rgba4f(v);
    }

    LuaConsoleUI::Streamer    LuaConsoleUI::file()
    {
        return Streamer(*this, m_channel.file);
    }
    
    void        LuaConsoleUI::file(const std::filesystem::path&v)
    {
        _submit(m_channel.file, v.string());
    }
    
    void        LuaConsoleUI::file(std::string_view txt)
    {
        _submit(m_channel.file, txt);
    }
    
    void        LuaConsoleUI::file(set_k, const color_t& v)
    {
        m_channel.file.color    = rgba4f(v);
    }

    LuaConsoleUI::Streamer    LuaConsoleUI::info()
    {
        return Streamer(*this, m_channel.info);
    }
    
    void        LuaConsoleUI::info(std::string_view txt)
    {
        _submit(m_channel.info, txt);
    }
    
    void        LuaConsoleUI::info(set_k, const color_t& v)
    {
        m_channel.info.color = rgba4f(v);
    }

    LuaConsoleUI::Streamer    LuaConsoleUI::output()
    {
        return Streamer(*this, m_channel.output);
    }
    
    void        LuaConsoleUI::output(std::string_view txt)
    {
        _submit(m_channel.output, txt);
    }
    
    void        LuaConsoleUI::output(set_k, const color_t& v)
    {
        m_channel.output.color = rgba4f(v);
    }

    void        LuaConsoleUI::submit(const ExecuteFileEvent&evt)
    {
        file(evt.file());
        if(!evt.output().empty())
            output(evt.output());
        if(!evt.warning().empty())
            warning(evt.warning());
        if(!evt.error().empty())
            error(evt.error());
        if(evt.error_code() != std::error_code())
            _submit(m_channel.errorCode, evt.error_code().message());
    }
    
    void        LuaConsoleUI::submit(const ExecuteStringEvent&evt)
    {
        command(evt.command());
        if(!evt.output().empty())
            output(evt.output());
        if(!evt.warning().empty())
            warning(evt.warning());
        if(!evt.error().empty())
            error(evt.error());
        if(evt.error_code() != std::error_code())
            _submit(m_channel.errorCode, evt.error_code().message());
    }
    
    LuaConsoleUI::Streamer    LuaConsoleUI::warning()
    {
        return Streamer(*this, m_channel.warning);
    }
    
    void        LuaConsoleUI::warning(std::string_view txt)
    {
        _submit(m_channel.warning, txt);
    }
    
    void        LuaConsoleUI::warning(set_k, const color_t& v)
    {
        m_channel.warning.color = rgba4f(v);
    }


////////////////////////////////////////////////////////////////////////////////

    LuaConsoleUI::Streamer::Streamer(LuaConsoleUI& ui, const Channel& ch) : m_ui(ui), m_channel(ch)
    {
    }

    LuaConsoleUI::Streamer::~Streamer()
    {
        _post();
    }

    void LuaConsoleUI::Streamer::_post()
    {
        if(m_buffer.empty())
            return;
        m_ui._submit(m_channel, m_buffer);
        m_buffer.clear();
    }

    bool    LuaConsoleUI::Streamer::write(const char*buf, size_t cb) 
    {
        if(buf && cb){
            m_buffer += std::string_view(buf, cb);
        }
        return true;
    }

////////////////////////////////////////////////////////////////////////////////

    LuaConsoleUIWriter::LuaConsoleUIWriter() = default;
    LuaConsoleUIWriter::LuaConsoleUIWriter(const LuaConsoleUIWriter&) = default;
    LuaConsoleUIWriter::~LuaConsoleUIWriter() = default;

    LuaConsoleUI* LuaConsoleUIWriter::element()
    {
        return static_cast<LuaConsoleUI*>(m_ui);
    }
    
    LuaConsoleUIWriter::LuaConsoleUIWriter(LuaConsoleUI* ui) : tachyon::UIConsoleWriter(ui)
    {
    }

    void    LuaConsoleUIWriter::command(const color_t& v)
    {
        if(LuaConsoleUI*p  = element())
            p->command(SET, v);
    }
    
    void    LuaConsoleUIWriter::debug(const color_t& v)
    {
        if(LuaConsoleUI*p  = element())
            p->debug(SET, v);
    }
    
    void    LuaConsoleUIWriter::error(const color_t& v)
    {
        if(LuaConsoleUI*p  = element())
            p->error(SET, v);
    }
    
    void    LuaConsoleUIWriter::error_code(const color_t& v)
    {
        if(LuaConsoleUI*p  = element())
            p->error_code(SET, v);
    }
    
    void    LuaConsoleUIWriter::file(const color_t& v)
    {
        if(LuaConsoleUI*p  = element())
            p->file(SET, v);
    }
    
    void    LuaConsoleUIWriter::info(const color_t& v)
    {
        if(LuaConsoleUI*p  = element())
            p->info(SET, v);
    }
    
    void    LuaConsoleUIWriter::output(const color_t& v)
    {
        if(LuaConsoleUI*p  = element())
            p->output(SET, v);
    }
    
    void    LuaConsoleUIWriter::warning(const color_t& v)
    {
        if(LuaConsoleUI*p  = element())
            p->warning(SET, v);
    }

}

