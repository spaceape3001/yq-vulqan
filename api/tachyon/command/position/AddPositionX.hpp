////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/command/spatial/PositionCommand.hpp>

namespace yq::tachyon {

    //! Instructs an object to adjust (self-increment) their position by given amount
    class AddPositionˣ : public PositionCommand {
        YQ_OBJECT_DECLARE(AddPositionˣ, PositionCommand)
    public:
        AddPositionˣ(const Header&, double Δx);
    
        static void init_info();
        
        double  Δx() const { return m_Δx; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;
    protected:
        
        AddPositionˣ(const AddPositionˣ&, const Header&);
        AddPositionˣ(const Header&);
        ~AddPositionˣ();

    private:
        double  m_Δx = 0.0;
        
        AddPositionˣ(const AddPositionˣ&) = delete;
        AddPositionˣ(AddPositionˣ&&) = delete;
        AddPositionˣ& operator=(const AddPositionˣ&);
        AddPositionˣ& operator=(AddPositionˣ&&);
    };
}
