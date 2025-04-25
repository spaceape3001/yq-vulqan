////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/command/spatial/SizeCommand.hpp>
#include <yq/vector/Vector1.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's z-position
    class AddSizeᶻ : public SizeCommand {
        YQ_OBJECT_DECLARE(AddSizeᶻ, SizeCommand)
    public:
        AddSizeᶻ(const Header&, double);
        
        static void init_info();
        
        double  Δz() const { return m_Δz; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        AddSizeᶻ(const AddSizeᶻ&, const Header&);
        AddSizeᶻ(const Header&);
        ~AddSizeᶻ();

    private:
        double  m_Δz = 0.0;
        
        AddSizeᶻ(const AddSizeᶻ&) = delete;
        AddSizeᶻ(AddSizeᶻ&&) = delete;
        AddSizeᶻ& operator=(const AddSizeᶻ&) = delete;
        AddSizeᶻ& operator=(AddSizeᶻ&&) = delete;
    };
}
