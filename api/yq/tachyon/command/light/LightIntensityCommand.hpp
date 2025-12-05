////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/LightCommand.hpp>

namespace yq::tachyon {
    class LightIntensityCommand : public LightCommand {
        YQ_OBJECT_DECLARE(LightIntensityCommand, LightCommand)
    public:
        LightIntensityCommand(const Header&, float);
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

        static void init_meta();
        
        float   intensity() const { return m_intensity; }

    protected:
        LightIntensityCommand(const LightIntensityCommand&, const Header&);
        virtual ~LightIntensityCommand();
        
    private:
    
        float   m_intensity;

        LightIntensityCommand(const LightIntensityCommand&) = delete;
        LightIntensityCommand(LightIntensityCommand&&) = delete;
        LightIntensityCommand& operator=(const LightIntensityCommand&) = delete;
        LightIntensityCommand& operator=(LightIntensityCommand&&) = delete;
    };
}
