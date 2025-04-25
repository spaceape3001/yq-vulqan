////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/command/spatial/SizeCommand.hpp>
#include <yq/vector/Vector1.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's x-position
    class MultiplyMinSizeˣ : public SizeCommand {
        YQ_OBJECT_DECLARE(MultiplyMinSizeˣ, SizeCommand)
    public:
        MultiplyMinSizeˣ(const Header&, double);
        
        static void init_info();
        
        double  δx() const { return m_δx; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MultiplyMinSizeˣ(const MultiplyMinSizeˣ&, const Header&);
        MultiplyMinSizeˣ(const Header&);
        ~MultiplyMinSizeˣ();

    private:
        double  m_δx = 0.0;
        
        MultiplyMinSizeˣ(const MultiplyMinSizeˣ&) = delete;
        MultiplyMinSizeˣ(MultiplyMinSizeˣ&&) = delete;
        MultiplyMinSizeˣ& operator=(const MultiplyMinSizeˣ&) = delete;
        MultiplyMinSizeˣ& operator=(MultiplyMinSizeˣ&&) = delete;
    };
}
