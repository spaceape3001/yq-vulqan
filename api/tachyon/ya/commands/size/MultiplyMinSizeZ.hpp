////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/commands/spatial/SizeCommand.hpp>
#include <yq/vector/Vector1.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's z-position
    class MultiplyMinSizeᶻ : public SizeCommand {
        YQ_OBJECT_DECLARE(MultiplyMinSizeᶻ, SizeCommand)
    public:
        MultiplyMinSizeᶻ(const Header&, double);
        
        static void init_info();
        
        double  δz() const { return m_δz; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MultiplyMinSizeᶻ(const MultiplyMinSizeᶻ&, const Header&);
        MultiplyMinSizeᶻ(const Header&);
        ~MultiplyMinSizeᶻ();

    private:
        double  m_δz = 0.0;
        
        MultiplyMinSizeᶻ(const MultiplyMinSizeᶻ&) = delete;
        MultiplyMinSizeᶻ(MultiplyMinSizeᶻ&&) = delete;
        MultiplyMinSizeᶻ& operator=(const MultiplyMinSizeᶻ&) = delete;
        MultiplyMinSizeᶻ& operator=(MultiplyMinSizeᶻ&&) = delete;
    };
}
