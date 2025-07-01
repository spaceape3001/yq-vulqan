////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/command/ColorCommand.hpp>
#include <yq/color/RGBA.hpp>

namespace yq::tachyon {
    class SetBgColorCommand : public ColorCommand {
        YQ_OBJECT_DECLARE(SetBgColorCommand, ColorCommand)
    public:
        SetBgColorCommand(const Header&, const RGBA4F&);
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

        const RGBA4F&   bgcolor() const { return m_bgColor; }
        void            set_bgcolor(const RGBA4F&);

        static void init_meta();

    protected:
        SetBgColorCommand(const SetBgColorCommand&, const Header&);
        virtual ~SetBgColorCommand();
        
    private:
    
        RGBA4F      m_bgColor;

        SetBgColorCommand(const SetBgColorCommand&) = delete;
        SetBgColorCommand(SetBgColorCommand&&) = delete;
        SetBgColorCommand& operator=(const SetBgColorCommand&) = delete;
        SetBgColorCommand& operator=(SetBgColorCommand&&) = delete;
    };
}
