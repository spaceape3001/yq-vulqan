////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/commands/SpatialCommand.hpp>
#include <yq/vector/Vector1.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's x-position
    class AddScaleˣ : public SpatialCommand {
        YQ_OBJECT_DECLARE(AddScaleˣ, SpatialCommand)
    public:
        AddScaleˣ(const Header&, double);
        
        static void init_info();
        
        double  x() const { return m_x; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        AddScaleˣ(const AddScaleˣ&, const Header&);
        ~AddScaleˣ();

    private:
        double const  m_x;
        
        AddScaleˣ(const AddScaleˣ&) = delete;
        AddScaleˣ(AddScaleˣ&&) = delete;
        AddScaleˣ& operator=(const AddScaleˣ&) = delete;
        AddScaleˣ& operator=(AddScaleˣ&&) = delete;
    };
}
