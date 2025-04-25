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
    class MultiplySizeˣ : public SizeCommand {
        YQ_OBJECT_DECLARE(MultiplySizeˣ, SizeCommand)
    public:
        MultiplySizeˣ(const Header&, double);
        
        static void init_info();
        
        double  δx() const { return m_δx; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MultiplySizeˣ(const MultiplySizeˣ&, const Header&);
        MultiplySizeˣ(const Header&);
        ~MultiplySizeˣ();

    private:
        double  m_δx = 0.0;
        
        MultiplySizeˣ(const MultiplySizeˣ&) = delete;
        MultiplySizeˣ(MultiplySizeˣ&&) = delete;
        MultiplySizeˣ& operator=(const MultiplySizeˣ&) = delete;
        MultiplySizeˣ& operator=(MultiplySizeˣ&&) = delete;
    };
}
