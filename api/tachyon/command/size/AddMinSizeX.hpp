////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/command/spatial/SizeCommand.hpp>
#include <yq/vector/Vector1.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's x-scale
    class AddMinSizeˣ : public SizeCommand {
        YQ_OBJECT_DECLARE(AddMinSizeˣ, SizeCommand)
    public:
        AddMinSizeˣ(const Header&, double);
        
        static void init_info();
        
        double  Δx() const { return m_Δx; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        AddMinSizeˣ(const AddMinSizeˣ&, const Header&);
        AddMinSizeˣ(const Header&);
        ~AddMinSizeˣ();

    private:
        double  m_Δx = 0.0;
        
        AddMinSizeˣ(const AddMinSizeˣ&) = delete;
        AddMinSizeˣ(AddMinSizeˣ&&) = delete;
        AddMinSizeˣ& operator=(const AddMinSizeˣ&) = delete;
        AddMinSizeˣ& operator=(AddMinSizeˣ&&) = delete;
    };
}
