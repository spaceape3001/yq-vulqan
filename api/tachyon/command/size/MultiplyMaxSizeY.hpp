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
    class MultiplyMaxSizeʸ : public SizeCommand {
        YQ_OBJECT_DECLARE(MultiplyMaxSizeʸ, SizeCommand)
    public:
        MultiplyMaxSizeʸ(const Header&, double);
        
        static void init_info();
        
        double  δy() const { return m_δy; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MultiplyMaxSizeʸ(const MultiplyMaxSizeʸ&, const Header&);
        MultiplyMaxSizeʸ(const Header&);
        ~MultiplyMaxSizeʸ();

    private:
        double  m_δy = 0.0;
        
        MultiplyMaxSizeʸ(const MultiplyMaxSizeʸ&) = delete;
        MultiplyMaxSizeʸ(MultiplyMaxSizeʸ&&) = delete;
        MultiplyMaxSizeʸ& operator=(const MultiplyMaxSizeʸ&) = delete;
        MultiplyMaxSizeʸ& operator=(MultiplyMaxSizeʸ&&) = delete;
    };
}
