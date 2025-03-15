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
    class MultiplyMaxSizeʷ : public SizeCommand {
        YQ_OBJECT_DECLARE(MultiplyMaxSizeʷ, SizeCommand)
    public:
        MultiplyMaxSizeʷ(const Header&, double);
        
        static void init_info();
        
        double  δw() const { return m_δw; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MultiplyMaxSizeʷ(const MultiplyMaxSizeʷ&, const Header&);
        MultiplyMaxSizeʷ(const Header&);
        ~MultiplyMaxSizeʷ();

    private:
        double  m_δw = 0.0;
        
        MultiplyMaxSizeʷ(const MultiplyMaxSizeʷ&) = delete;
        MultiplyMaxSizeʷ(MultiplyMaxSizeʷ&&) = delete;
        MultiplyMaxSizeʷ& operator=(const MultiplyMaxSizeʷ&) = delete;
        MultiplyMaxSizeʷ& operator=(MultiplyMaxSizeʷ&&) = delete;
    };
}
