////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/command/spatial/SizeCommand.hpp>
#include <yq/vector/Vector1.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's y-position
    class MultiplySizeʸ : public SizeCommand {
        YQ_OBJECT_DECLARE(MultiplySizeʸ, SizeCommand)
    public:
        MultiplySizeʸ(const Header&, double);
        
        static void init_info();
        
        double  δy() const { return m_δy; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MultiplySizeʸ(const MultiplySizeʸ&, const Header&);
        MultiplySizeʸ(const Header&);
        ~MultiplySizeʸ();

    private:
        double  m_δy = 0.0;
        
        MultiplySizeʸ(const MultiplySizeʸ&) = delete;
        MultiplySizeʸ(MultiplySizeʸ&&) = delete;
        MultiplySizeʸ& operator=(const MultiplySizeʸ&) = delete;
        MultiplySizeʸ& operator=(MultiplySizeʸ&&) = delete;
    };
}
