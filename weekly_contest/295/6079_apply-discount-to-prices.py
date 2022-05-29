class Solution:
    def discountPrices(self, sentence: str, discount: int) -> str:
        contexts = sentence.split(" ")
        for idx, context in enumerate(contexts):
            if context[0] == "$":
                t = context[1:]
                try:
                    t = float(t)
                    t = str(round(t * (1 - discount / 100), 2))
                    context = context[0] + t
                    if len(context.split(".")[-1]) == 1:
                        context += "0"
                    contexts[idx] = context
                except Exception:
                    continue
        return " ".join(contexts)
