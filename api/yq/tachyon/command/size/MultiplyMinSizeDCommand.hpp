////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/SizeCommand.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's x-position
    class MultiplyMinSizeDCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(MultiplyMinSizeDCommand, SizeCommand)
    public:
        MultiplyMinSizeDCommand(const Header&, double);
        
        static void init_meta();
        
        double  δ() const { return m_δ; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MultiplyMinSizeDCommand(const MultiplyMinSizeDCommand&, const Header&);
        ~MultiplyMinSizeDCommand();
        MultiplyMinSizeDCommand(const Header&);

    private:
        double  m_δ = 0.0;
        
        MultiplyMinSizeDCommand(const MultiplyMinSizeDCommand&) = delete;
        MultiplyMinSizeDCommand(MultiplyMinSizeDCommand&&) = delete;
        MultiplyMinSizeDCommand& operator=(const MultiplyMinSizeDCommand&) = delete;
        MultiplyMinSizeDCommand& operator=(MultiplyMinSizeDCommand&&) = delete;
    };
}
