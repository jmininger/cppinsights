/******************************************************************************
 *
 * C++ Insights, copyright (C) by Andreas Fertig
 * Distributed under an MIT license. See LICENSE for details
 *
 ****************************************************************************/

#ifndef INSIGHTS_RANGE_FOR_STMT_HANDLER_H
#define INSIGHTS_RANGE_FOR_STMT_HANDLER_H

#include "clang/AST/AST.h"
#include "clang/AST/ASTContext.h"
#include "clang/ASTMatchers/ASTMatchFinder.h"
#include "clang/ASTMatchers/ASTMatchers.h"
#include "clang/Rewrite/Core/Rewriter.h"

#include "InsightsBase.h"
//-----------------------------------------------------------------------------

namespace clang::insights {

/// \brief Transform range-based for-loops into their internal for-loop representation.
///
/// This shows all the variables involded and the scoping, as described in the C++ standard.
class RangeForStmtHandler final : public ast_matchers::MatchFinder::MatchCallback, public InsightsBase
{
public:
    RangeForStmtHandler(Rewriter& rewrite, ast_matchers::MatchFinder& matcher);
    void run(const ast_matchers::MatchFinder::MatchResult& result) override;
};
//-----------------------------------------------------------------------------

}  // namespace clang::insights

#endif /* INSIGHTS_RANGE_FOR_STMT_HANDLER_H */
