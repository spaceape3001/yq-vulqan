////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/ColorCommand.hpp>
#include <yq/color/RGBA.hpp>

namespace yq::tachyon {
    class SetColorCommand : public ColorCommand {
        YQ_OBJECT_DECLARE(SetColorCommand, ColorCommand)
    public:
        SetColorCommand(const Header&, const RGBA4F&);
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

        const RGBA4F&   color() const { return m_color; }
        void            set_color(const RGBA4F&);

        static void init_meta();

    protected:
        SetColorCommand(const SetColorCommand&, const Header&);
        virtual ~SetColorCommand();
        
    private:
    
        RGBA4F      m_color;

        SetColorCommand(const SetColorCommand&) = delete;
        SetColorCommand(SetColorCommand&&) = delete;
        SetColorCommand& operator=(const SetColorCommand&) = delete;
        SetColorCommand& operator=(SetColorCommand&&) = delete;
    };
}
