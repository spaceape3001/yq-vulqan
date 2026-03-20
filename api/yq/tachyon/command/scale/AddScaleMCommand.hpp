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
    class AddScaleMCommand : public ScaleCommand {
        YQ_OBJECT_DECLARE(AddScaleMCommand, ScaleCommand)
    public:
        AddScaleMCommand(const Header&, Meter);
    
        Meter   Δscale() const  { return m_Δscale; }
        
        static void init_meta();
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        ~AddScaleMCommand();
        AddScaleMCommand(const AddScaleMCommand&, const Header&);
        AddScaleMCommand(const Header&);

    private:
        Meter  m_Δscale = ZERO;
        
        AddScaleMCommand(const AddScaleMCommand&) = delete;
        AddScaleMCommand(AddScaleMCommand&&) = delete;
        AddScaleMCommand& operator=(const AddScaleMCommand&) = delete;
        AddScaleMCommand& operator=(AddScaleMCommand&&) = delete;
    };
}
