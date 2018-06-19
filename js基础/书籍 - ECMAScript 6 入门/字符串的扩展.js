/*
1.转义:将当前的码点(utf8,ascii,unicode相应的数字码点)转义为相应得字符 '\172' === 'z'
2.JavaScript内部，字符以UTF-16的格式储存，每个字符固定为2个字节;
  对于那些需要4个字节储存的字符（Unicode码点大于0xFFFF的字符），JavaScript会认为它们是两个字符
所以 charAt方法无法读取整个字符，charCodeAt方法只能分别返回前两个字节和后两个字节的值(前后字节的码点)

3. str.codePointAt(num);//num 字符串索引,查询索引下的字符的码点

   String.fromCodePoint(code);//code就是码点(10,16,8,2进制都可以),返回码点对应的字符

   for of 可以识别32位的字符

4. s.startsWith()  s.endsWith() s.includes() //boolean
   str.repeat(num) ;//字符串重复几次

5. (未实现)
   str.padStart(num,padstr);//从头补全str
   str.padEnd(num,padstr);//从后补全str
   注释：num指定str的长度,padstr字符补全str不足的长度,padstr该参数没有就默认为空格
        '12'.padStart(10, 'YYYY-MM-DD') // "YYYY-MM-12"

6.模板字符串
  `abc${name} ${age}`
注意：{}内可以放任意js表达式  ${fn()}

7.String.prototype.includes() ==>字符串是否包含给定的值

*/