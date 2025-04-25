////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/api/MG.hpp>
#include <tachyon/command/TachyonCommand.hpp>
#include <tachyon/api/TypedID.hpp>
#include <tachyon/typedef/thread.hpp>

namespace yq::tachyon {
    class UnsnoopCommand : public TachyonCommand {
        YQ_OBJECT_DECLARE(UnsnoopCommand, TachyonCommand)
    public:
        UnsnoopCommand(const Header&, TypedID);

        constexpr TypedID     listener() const { return m_listener; }
        
        static void init_info();
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        UnsnoopCommand(const UnsnoopCommand&, const Header&);
        ~UnsnoopCommand();
        
    private:
        const TypedID     m_listener;
        
        UnsnoopCommand(const UnsnoopCommand&) = delete;
        UnsnoopCommand(UnsnoopCommand&&) = delete;
        UnsnoopCommand& operator=(const UnsnoopCommand&) = delete;
        UnsnoopCommand& operator=(UnsnoopCommand&&) = delete;
    };
}
