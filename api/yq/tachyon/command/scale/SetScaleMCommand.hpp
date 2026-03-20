////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/spatial/ScaleCommand.hpp>
#include <yq/units.hpp>


namespace yq::tachyon {

    //! Instructs an object to set it's scale
    class SetScaleMCommand : public ScaleCommand {
        YQ_OBJECT_DECLARE(SetScaleMCommand, ScaleCommand)
    public:
        SetScaleMCommand(const Header&, const Meter&);
    
        Meter   scale() const  { return m_scale; }
        
        static void init_meta();
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        ~SetScaleMCommand();
        SetScaleMCommand(const SetScaleMCommand&, const Header&);
    

    private:
        Meter  m_scale;
        
        SetScaleMCommand(const SetScaleMCommand&) = delete;
        SetScaleMCommand(SetScaleMCommand&&) = delete;
        SetScaleMCommand& operator=(const SetScaleMCommand&) = delete;
        SetScaleMCommand& operator=(SetScaleMCommand&&) = delete;
    };
}
