////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/SizeCommand.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's x-position
    class MultiplyMaxSizeDCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(MultiplyMaxSizeDCommand, SizeCommand)
    public:
        MultiplyMaxSizeDCommand(const Header&, double);
        
        static void init_meta();
        
        double  δ() const { return m_δ; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MultiplyMaxSizeDCommand(const MultiplyMaxSizeDCommand&, const Header&);
        ~MultiplyMaxSizeDCommand();
        MultiplyMaxSizeDCommand(const Header&);

    private:
        double  m_δ = 0.0;
        
        MultiplyMaxSizeDCommand(const MultiplyMaxSizeDCommand&) = delete;
        MultiplyMaxSizeDCommand(MultiplyMaxSizeDCommand&&) = delete;
        MultiplyMaxSizeDCommand& operator=(const MultiplyMaxSizeDCommand&) = delete;
        MultiplyMaxSizeDCommand& operator=(MultiplyMaxSizeDCommand&&) = delete;
    };
}
