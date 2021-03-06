#ifndef TCNAF_AST_EXPRESSION_HPP
#define TCNAF_AST_EXPRESSION_HPP

#include <common.hpp>

#include <cstdint>
#include <string>

namespace tcnaf {

class ExpressionConstInteger : public BaseExpression {
 public:
  int64_t value;
  ExpressionConstInteger(int64_t v) :
    value(v) {}
  virtual ReturnType getReturnType() {
    return RETTYPE_INT;
  }
  virtual std::string* compile(int level);
  virtual bool validate(VariableStore&);
};

class ExpressionConstFloat : public BaseExpression {
 public:
  double value;
  ExpressionConstFloat(double v) :
    value(v) {}
  virtual ReturnType getReturnType() {
    return RETTYPE_FLOAT;
  }
  virtual std::string* compile(int level);
  virtual bool validate(VariableStore&);
};

class ExpressionVariable : public BaseExpression {
 public:
  Variable reference;
  ExpressionVariable(const char* id) {
    reference.type = RETTYPE_UNKNOWN;
    reference.name = id;
  }
  virtual ReturnType getReturnType() {
    return reference.type;
  }
  virtual std::string* compile(int level);
  virtual bool validate(VariableStore&);
};

class ExpressionNegate : public BaseExpression {
 public:
  BaseExpression* expr;
  ExpressionNegate(BaseExpression* e) :
    expr(e) {}
  virtual ReturnType getReturnType() {
    return expr->getReturnType();
  }
  virtual std::string* compile(int level);
  virtual bool validate(VariableStore&);
};

class ExpressionAdd : public BaseExpression {
 public:
  BaseExpression* expr_a;
  BaseExpression* expr_b;
  ExpressionAdd(BaseExpression* a, BaseExpression* b) :
    expr_a(a),
    expr_b(b) {}
  virtual ReturnType getReturnType() {
    ReturnType at = expr_a->getReturnType();
    ReturnType bt = expr_b->getReturnType();
    if(at == RETTYPE_INT && bt == RETTYPE_INT) {
      return RETTYPE_INT;
    } else if((at == RETTYPE_INT && bt == RETTYPE_FLOAT) || (at == RETTYPE_FLOAT && bt == RETTYPE_INT)) {
      return RETTYPE_FLOAT;
    } else if(at == RETTYPE_FLOAT && bt == RETTYPE_FLOAT) {
      return RETTYPE_FLOAT;
    } else {
      return RETTYPE_UNKNOWN;
    }
  }
  virtual std::string* compile(int level);
  virtual bool validate(VariableStore&);
};

class ExpressionSub : public BaseExpression {
 public:
  BaseExpression* expr_a;
  BaseExpression* expr_b;
  ExpressionSub(BaseExpression* a, BaseExpression* b) :
    expr_a(a),
    expr_b(b) {}
  virtual ReturnType getReturnType() {
    ReturnType at = expr_a->getReturnType();
    ReturnType bt = expr_b->getReturnType();
    if(at == RETTYPE_INT && bt == RETTYPE_INT) {
      return RETTYPE_INT;
    } else if((at == RETTYPE_INT && bt == RETTYPE_FLOAT) || (at == RETTYPE_FLOAT && bt == RETTYPE_INT)) {
      return RETTYPE_FLOAT;
    } else if(at == RETTYPE_FLOAT && bt == RETTYPE_FLOAT) {
      return RETTYPE_FLOAT;
    } else {
      return RETTYPE_UNKNOWN;
    }
  }
  virtual std::string* compile(int level);
  virtual bool validate(VariableStore&);
};

class ExpressionMul : public BaseExpression {
 public:
  BaseExpression* expr_a;
  BaseExpression* expr_b;
  ExpressionMul(BaseExpression* a, BaseExpression* b) :
    expr_a(a),
    expr_b(b) {}
  virtual ReturnType getReturnType() {
    ReturnType at = expr_a->getReturnType();
    ReturnType bt = expr_b->getReturnType();
    if(at == RETTYPE_INT && bt == RETTYPE_INT) {
      return RETTYPE_INT;
    } else if((at == RETTYPE_INT && bt == RETTYPE_FLOAT) || (at == RETTYPE_FLOAT && bt == RETTYPE_INT)) {
      return RETTYPE_FLOAT;
    } else if(at == RETTYPE_FLOAT && bt == RETTYPE_FLOAT) {
      return RETTYPE_FLOAT;
    } else {
      return RETTYPE_UNKNOWN;
    }
  }
  virtual std::string* compile(int level);
  virtual bool validate(VariableStore&);
};

class ExpressionDiv : public BaseExpression {
 public:
  BaseExpression* expr_a;
  BaseExpression* expr_b;
  ExpressionDiv(BaseExpression* a, BaseExpression* b) :
    expr_a(a),
    expr_b(b) {}
  virtual ReturnType getReturnType() {
    ReturnType at = expr_a->getReturnType();
    ReturnType bt = expr_b->getReturnType();
    if(at == RETTYPE_INT && bt == RETTYPE_INT) {
      return RETTYPE_INT;
    } else if((at == RETTYPE_INT && bt == RETTYPE_FLOAT) || (at == RETTYPE_FLOAT && bt == RETTYPE_INT)) {
      return RETTYPE_FLOAT;
    } else if(at == RETTYPE_FLOAT && bt == RETTYPE_FLOAT) {
      return RETTYPE_FLOAT;
    } else {
      return RETTYPE_UNKNOWN;
    }
  }
  virtual std::string* compile(int level);
  virtual bool validate(VariableStore&);
};

class ExpressionLogical : public BaseExpression {
 public:
  BoolOp operation;
  BaseExpression* expr_a;
  BaseExpression* expr_b;
  ExpressionLogical(BoolOp op, BaseExpression* a, BaseExpression* b) :
    operation(op),
    expr_a(a),
    expr_b(b) {}
  virtual ReturnType getReturnType() {
    return RETTYPE_BOOL;
  }
  virtual std::string* compile(int level);
  virtual bool validate(VariableStore&);
};

class ExpressionAssignment : public BaseExpression {
 public:
  Variable reference;
  BaseExpression* expr;
  ExpressionAssignment(const char* id, BaseExpression* e) :
    expr(e) {
      reference.type = RETTYPE_UNKNOWN;
      reference.name = id;
    }
  virtual ReturnType getReturnType() {
    return RETTYPE_VOID;
  }
  virtual std::string* compile(int level);
  virtual bool validate(VariableStore&);
};

}  // namespace tcnaf

#endif /*TCNAF_AST_EXPRESSION_HPP*/