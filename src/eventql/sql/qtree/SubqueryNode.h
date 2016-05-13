/**
 * This file is part of the "libcsql" project
 *   Copyright (c) 2015 Paul Asmuth
 *
 * FnordMetric is free software: you can redistribute it and/or modify it under
 * the terms of the GNU General Public License v3.0. You should have received a
 * copy of the GNU General Public License along with this program. If not, see
 * <http://www.gnu.org/licenses/>.
 */
#pragma once
#include <eventql/util/stdtypes.h>
#include <eventql/util/option.h>
#include <eventql/sql/svalue.h>
#include <eventql/sql/qtree/TableExpressionNode.h>
#include <eventql/sql/qtree/ValueExpressionNode.h>
#include <eventql/sql/qtree/SelectListNode.h>

using namespace stx;

namespace csql {

class SubqueryNode : public TableExpressionNode {
public:

  SubqueryNode(
      RefPtr<QueryTreeNode> subquery,
      Vector<RefPtr<SelectListNode>> select_list,
      Option<RefPtr<ValueExpressionNode>> where_expr);

  SubqueryNode(const SubqueryNode& other);

  RefPtr<QueryTreeNode> subquery() const;

  Vector<RefPtr<SelectListNode>> selectList() const;
  Vector<String> outputColumns() const override;

  Vector<QualifiedColumn> allColumns() const override;

  size_t getColumnIndex(
      const String& column_name,
      bool allow_add = false) override;

  Option<RefPtr<ValueExpressionNode>> whereExpression() const;

  RefPtr<QueryTreeNode> deepCopy() const override;

  String toString() const override;

  const String& tableAlias() const;
  void setTableAlias(const String& alias);

  static void encode(
      QueryTreeCoder* coder,
      const SubqueryNode& node,
      stx::OutputStream* os);

  static RefPtr<QueryTreeNode> decode(
      QueryTreeCoder* coder,
      stx::InputStream* is);

protected:
  RefPtr<QueryTreeNode> subquery_;
  Vector<String> column_names_;
  Vector<RefPtr<SelectListNode>> select_list_;
  Option<RefPtr<ValueExpressionNode>> where_expr_;
  String alias_;
};

} // namespace csql
