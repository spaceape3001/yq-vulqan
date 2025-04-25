////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/command/spatial/PositionCommand.hpp>

namespace yq::tachyon {

    //! Instructs an object to adjust (self-increment) their position by given amount
    class AddPositionʷ : public PositionCommand {
        YQ_OBJECT_DECLARE(AddPositionʷ, PositionCommand)
    public:
        AddPositionʷ(const Header&, double Δw);
    
        static void init_info();
        
        double  Δw() const { return m_Δw; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;
    protected:
        
        AddPositionʷ(const AddPositionʷ&, const Header&);
        AddPositionʷ(const Header&);
        ~AddPositionʷ();

    private:
        double  m_Δw = 0.0;
        
        AddPositionʷ(const AddPositionʷ&) = delete;
        AddPositionʷ(AddPositionʷ&&) = delete;
        AddPositionʷ& operator=(const AddPositionʷ&);
        AddPositionʷ& operator=(AddPositionʷ&&);
    };
}
