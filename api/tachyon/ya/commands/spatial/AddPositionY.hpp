////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/commands/SpatialCommand.hpp>

namespace yq::tachyon {

    //! Instructs an object to adjust (self-increment) their position by given amount
    class AddPositionʸ : public SpatialCommand {
        YQ_OBJECT_DECLARE(AddPositionʸ, SpatialCommand)
    public:
        AddPositionʸ(const Header&, double Δy);
    
        static void init_info();
        
        double  Δy() const { return m_Δy; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        AddPositionʸ(const AddPositionʸ&, const Header&);
        AddPositionʸ(const Header&);
        ~AddPositionʸ();
        
    private:
        double  m_Δy = 0.0;

        AddPositionʸ(const AddPositionʸ&) = delete;
        AddPositionʸ(AddPositionʸ&&) = delete;
        AddPositionʸ& operator=(const AddPositionʸ&) = delete;
        AddPositionʸ& operator=(AddPositionʸ&&) = delete;
    };
}
