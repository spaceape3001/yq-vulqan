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
    class AddScaleʸ : public SpatialCommand {
        YQ_OBJECT_DECLARE(AddScaleʸ, SpatialCommand)
    public:
        AddScaleʸ(const Header&, double);
        
        static void init_info();
        
        double  y() const { return m_y; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        AddScaleʸ(const AddScaleʸ&, const Header&);
        ~AddScaleʸ();

    private:
        double const  m_y;
        
        AddScaleʸ(const AddScaleʸ&) = delete;
        AddScaleʸ(AddScaleʸ&&) = delete;
        AddScaleʸ& operator=(const AddScaleʸ&) = delete;
        AddScaleʸ& operator=(AddScaleʸ&&) = delete;
    };
}
