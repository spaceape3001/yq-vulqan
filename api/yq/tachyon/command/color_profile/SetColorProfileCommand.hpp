////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/ColorProfileCommand.hpp>
#include <yq/tachyon/typedef/color_profile.hpp>

namespace yq::tachyon {
    class SetColorProfileCommand : public ColorProfileCommand {
        YQ_OBJECT_DECLARE(SetColorProfileCommand, ColorProfileCommand)
    public:
        SetColorProfileCommand(const Header&, const ColorProfileCPtr&);
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

        static void init_meta();
        
        const ColorProfileCPtr&     color_profile() const { return m_colorProfile; }

    protected:
        SetColorProfileCommand(const SetColorProfileCommand&, const Header&);
        virtual ~SetColorProfileCommand();
        
    private:
    
        ColorProfileCPtr            m_colorProfile;

        SetColorProfileCommand(const SetColorProfileCommand&) = delete;
        SetColorProfileCommand(SetColorProfileCommand&&) = delete;
        SetColorProfileCommand& operator=(const SetColorProfileCommand&) = delete;
        SetColorProfileCommand& operator=(SetColorProfileCommand&&) = delete;
    };
}
