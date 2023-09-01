module.exports = {
  parserOptions: {
    parser: '@babel/eslint-parser', // or 'babel-eslint'
    requireConfigFile: false,
  },
  extends: [
    // 다른 확장 규칙
    'plugin:vue/vue3-essential',  // Vue 3에 맞는 ESLint 규칙
  ],
};
