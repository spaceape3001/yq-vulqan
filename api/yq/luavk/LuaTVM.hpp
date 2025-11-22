////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

struct lua_State;

#include <yq/tachyon/api/Tachyon.hpp>
#include <yq/core/Stream.hpp>

namespace yq::tachyon {
    class LuaExecuteStringRequest;
    class LuaExecuteFileRequest;
    
    struct LuaChannel : public Stream {
        std::string*        buffer  = nullptr;
        virtual bool        write(const char* z, size_t cb);
        
        LuaChannel();
        ~LuaChannel();
    };
    
    class LuaTVM : public Tachyon {
        YQ_TACHYON_DECLARE(LuaTVM, Tachyon)
    public:
        LuaTVM();
        ~LuaTVM();
        
        static void init_meta();
        
    protected:
        virtual Execution   setup(const Context&) override;
        virtual Execution   tick(const Context&) override;
        virtual Execution   teardown(const Context&) override;

    private:
        lua_State*      m_lua       = nullptr;
        LuaChannel      m_output, m_error, m_warning;
        bool            m_init       = false;
        
        void    on_exec_file(const Ref<const LuaExecuteFileRequest>&);
        void    on_exec_string(const Ref<const LuaExecuteStringRequest>&);
    };
}
