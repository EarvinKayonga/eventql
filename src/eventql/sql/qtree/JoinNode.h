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

enum class JoinType {
  CARTESIAN, INNER, OUTER
};

class JoinNode : public TableExpressionNode {
public:

  struct InputColumnRef {
    String column;
    size_t table_idx;
    size_t column_idx;
  };

  static const uint8_t kHasWhereExprFlag = 1;
  static const uint8_t kHasJoinExprFlag = 2;

  JoinNode(
      JoinType join_type,
      RefPtr<QueryTreeNode> base_table,
      RefPtr<QueryTreeNode> joined_table,
      Vector<RefPtr<SelectListNode>> select_list,
      Option<RefPtr<ValueExpressionNode>> where_expr,
      Option<RefPtr<ValueExpressionNode>> join_expr);

  JoinNode(const JoinNode& other);

  JoinType joinType() const;

  RefPtr<QueryTreeNode> baseTable() const;
  RefPtr<QueryTreeNode> joinedTable() const;

  Vector<RefPtr<SelectListNode>> selectList() const;

  Vector<String> outputColumns() const override;

  Vector<QualifiedColumn> allColumns() const override;

  const Vector<InputColumnRef>& inputColumnMap() const;

  size_t getColumnIndex(
      const String& column_name,
      bool allow_add = false) override;

  size_t getInputColumnIndex(
      const String& column_name,
      bool allow_add = false);

  Option<RefPtr<ValueExpressionNode>> whereExpression() const;
  Option<RefPtr<ValueExpressionNode>> joinCondition() const;

  RefPtr<QueryTreeNode> deepCopy() const override;

  String toString() const override;

  static void encode(
      QueryTreeCoder* coder,
      const JoinNode& node,
      stx::OutputStream* os);

  static RefPtr<QueryTreeNode> decode(
      QueryTreeCoder* coder,
      stx::InputStream* is);

protected:


  JoinType join_type_;
  RefPtr<QueryTreeNode> base_table_;
  RefPtr<QueryTreeNode> joined_table_;
  Vector<InputColumnRef> input_map_;
  Vector<String> column_names_;
  Vector<RefPtr<SelectListNode>> select_list_;
  Option<RefPtr<ValueExpressionNode>> where_expr_;
  Option<RefPtr<ValueExpressionNode>> join_cond_;
};

} // namespace csql
