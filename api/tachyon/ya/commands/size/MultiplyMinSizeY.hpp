////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/commands/spatial/SizeCommand.hpp>
#include <yq/vector/Vector1.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's y-position
    class MultiplyMinSizeʸ : public SizeCommand {
        YQ_OBJECT_DECLARE(MultiplyMinSizeʸ, SizeCommand)
    public:
        MultiplyMinSizeʸ(const Header&, double);
        
        static void init_info();
        
        double  δy() const { return m_δy; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MultiplyMinSizeʸ(const MultiplyMinSizeʸ&, const Header&);
        MultiplyMinSizeʸ(const Header&);
        ~MultiplyMinSizeʸ();

    private:
        double  m_δy = 0.0;
        
        MultiplyMinSizeʸ(const MultiplyMinSizeʸ&) = delete;
        MultiplyMinSizeʸ(MultiplyMinSizeʸ&&) = delete;
        MultiplyMinSizeʸ& operator=(const MultiplyMinSizeʸ&) = delete;
        MultiplyMinSizeʸ& operator=(MultiplyMinSizeʸ&&) = delete;
    };
}
