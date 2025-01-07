////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/commands/SpatialCommand.hpp>
#include <yq/vector/Vector1.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's y-position
    class SetPositionʸ : public SpatialCommand {
        YQ_OBJECT_DECLARE(SetPositionʸ, SpatialCommand)
    public:
        SetPositionʸ(const Header&, double);
        
        static void init_info();
        
        double  y() const { return m_y; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetPositionʸ(const SetPositionʸ&, const Header&);
        ~SetPositionʸ();
    private:
        double const  m_y;
        
        SetPositionʸ(const SetPositionʸ&) = delete;
        SetPositionʸ(SetPositionʸ&&) = delete;
        SetPositionʸ& operator=(const SetPositionʸ&) = delete;
        SetPositionʸ& operator=(SetPositionʸ&&) = delete;
    };
}
