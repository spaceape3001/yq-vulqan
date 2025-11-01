////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/spatial/SizeCommand.hpp>
#include <yq/vector/Vector1.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's x-position
    class MultiplyMaxSizeˣCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(MultiplyMaxSizeˣCommand, SizeCommand)
    public:
        MultiplyMaxSizeˣCommand(const Header&, double);
        
        static void init_meta();
        
        double  δx() const { return m_δx; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MultiplyMaxSizeˣCommand(const MultiplyMaxSizeˣCommand&, const Header&);
        MultiplyMaxSizeˣCommand(const Header&);
        ~MultiplyMaxSizeˣCommand();

    private:
        double  m_δx = 0.0;
        
        MultiplyMaxSizeˣCommand(const MultiplyMaxSizeˣCommand&) = delete;
        MultiplyMaxSizeˣCommand(MultiplyMaxSizeˣCommand&&) = delete;
        MultiplyMaxSizeˣCommand& operator=(const MultiplyMaxSizeˣCommand&) = delete;
        MultiplyMaxSizeˣCommand& operator=(MultiplyMaxSizeˣCommand&&) = delete;
    };
}
