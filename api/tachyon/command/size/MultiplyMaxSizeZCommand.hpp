////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/command/spatial/SizeCommand.hpp>
#include <yq/vector/Vector1.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's z-position
    class MultiplyMaxSizeᶻCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(MultiplyMaxSizeᶻCommand, SizeCommand)
    public:
        MultiplyMaxSizeᶻCommand(const Header&, double);
        
        static void init_meta();
        
        double  δz() const { return m_δz; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MultiplyMaxSizeᶻCommand(const MultiplyMaxSizeᶻCommand&, const Header&);
        MultiplyMaxSizeᶻCommand(const Header&);
        ~MultiplyMaxSizeᶻCommand();

    private:
        double  m_δz = 0.0;
        
        MultiplyMaxSizeᶻCommand(const MultiplyMaxSizeᶻCommand&) = delete;
        MultiplyMaxSizeᶻCommand(MultiplyMaxSizeᶻCommand&&) = delete;
        MultiplyMaxSizeᶻCommand& operator=(const MultiplyMaxSizeᶻCommand&) = delete;
        MultiplyMaxSizeᶻCommand& operator=(MultiplyMaxSizeᶻCommand&&) = delete;
    };
}
