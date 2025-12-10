////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/SizeCommand.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's x-position
    class MultiplyMinSize : public SizeCommand {
        YQ_OBJECT_DECLARE(MultiplyMinSize, SizeCommand)
    public:
        MultiplyMinSize(const Header&, double);
        
        static void init_meta();
        
        double  δ() const { return m_δ; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MultiplyMinSize(const MultiplyMinSize&, const Header&);
        ~MultiplyMinSize();
        MultiplyMinSize(const Header&);

    private:
        double  m_δ = 0.0;
        
        MultiplyMinSize(const MultiplyMinSize&) = delete;
        MultiplyMinSize(MultiplyMinSize&&) = delete;
        MultiplyMinSize& operator=(const MultiplyMinSize&) = delete;
        MultiplyMinSize& operator=(MultiplyMinSize&&) = delete;
    };
}
