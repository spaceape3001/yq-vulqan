////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/command/spatial/PositionCommand.hpp>

namespace yq::tachyon {

    //! Instructs an object to adjust (self-increment) their position by given amount
    class AddPositionᶻ : public PositionCommand {
        YQ_OBJECT_DECLARE(AddPositionᶻ, PositionCommand)
    public:
        AddPositionᶻ(const Header&, double Δz);
    
        static void init_info();
        
        double  Δz() const { return m_Δz; }
        virtual PostCPtr    clone(rebind_k, const Header&) const override;
        
    protected:
        AddPositionᶻ(const AddPositionᶻ&, const Header&);
        AddPositionᶻ(const Header&);
        ~AddPositionᶻ();
        
    private:
        double  m_Δz = 0.0;
        
        AddPositionᶻ(const AddPositionᶻ&) = delete;
        AddPositionᶻ(AddPositionᶻ&&) = delete;
        AddPositionᶻ& operator=(const AddPositionᶻ&) = delete;
        AddPositionᶻ& operator=(AddPositionᶻ&&) = delete;
    };
}
