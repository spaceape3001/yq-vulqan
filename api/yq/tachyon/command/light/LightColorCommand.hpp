////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/color/RGB.hpp>
#include <yq/tachyon/command/LightCommand.hpp>

namespace yq::tachyon {
    class LightColorCommand : public LightCommand {
        YQ_OBJECT_DECLARE(LightColorCommand, LightCommand)
    public:
        LightColorCommand(const Header&, const RGB3F&);
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

        static void init_meta();
        
        const RGB3F& color() const { return m_color; }
        void    set_color(const RGB3F&);

    protected:
        LightColorCommand(const LightColorCommand&, const Header&);
        virtual ~LightColorCommand();
        
    private:
    
        RGB3F       m_color;

        LightColorCommand(const LightColorCommand&) = delete;
        LightColorCommand(LightColorCommand&&) = delete;
        LightColorCommand& operator=(const LightColorCommand&) = delete;
        LightColorCommand& operator=(LightColorCommand&&) = delete;
    };
}
