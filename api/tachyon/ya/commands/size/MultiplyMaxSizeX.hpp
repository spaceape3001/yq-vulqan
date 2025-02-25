////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/commands/spatial/SizeCommand.hpp>
#include <yq/vector/Vector1.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's x-position
    class MultiplyMaxSizeˣ : public SizeCommand {
        YQ_OBJECT_DECLARE(MultiplyMaxSizeˣ, SizeCommand)
    public:
        MultiplyMaxSizeˣ(const Header&, double);
        
        static void init_info();
        
        double  δx() const { return m_δx; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MultiplyMaxSizeˣ(const MultiplyMaxSizeˣ&, const Header&);
        MultiplyMaxSizeˣ(const Header&);
        ~MultiplyMaxSizeˣ();

    private:
        double  m_δx = 0.0;
        
        MultiplyMaxSizeˣ(const MultiplyMaxSizeˣ&) = delete;
        MultiplyMaxSizeˣ(MultiplyMaxSizeˣ&&) = delete;
        MultiplyMaxSizeˣ& operator=(const MultiplyMaxSizeˣ&) = delete;
        MultiplyMaxSizeˣ& operator=(MultiplyMaxSizeˣ&&) = delete;
    };
}
