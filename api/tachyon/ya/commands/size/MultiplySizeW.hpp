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
    class MultiplySizeʷ : public SizeCommand {
        YQ_OBJECT_DECLARE(MultiplySizeʷ, SizeCommand)
    public:
        MultiplySizeʷ(const Header&, double);
        
        static void init_info();
        
        double  δw() const { return m_δw; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MultiplySizeʷ(const MultiplySizeʷ&, const Header&);
        MultiplySizeʷ(const Header&);
        ~MultiplySizeʷ();

    private:
        double  m_δw = 0.0;
        
        MultiplySizeʷ(const MultiplySizeʷ&) = delete;
        MultiplySizeʷ(MultiplySizeʷ&&) = delete;
        MultiplySizeʷ& operator=(const MultiplySizeʷ&) = delete;
        MultiplySizeʷ& operator=(MultiplySizeʷ&&) = delete;
    };
}
